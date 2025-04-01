WRITE_PROGRAM = True

# Generate the table
inpts = ['a2', 'a1', 'b', 's2', 's1']
outpt = ['q2', 'q1', 'o2', 'o1']
table = []

def conv_bin(bin_l):
    cur_place = 1
    val = 0
    for i in range(len(bin_l)):
        ind = (len(bin_l) - 1) - i
        if (bin_l[ind] == 1):
            val += cur_place
        cur_place *= 2
    return val
        
        

def computeOut(inp):
    a = [inp[0], inp[1]]
    b = inp[2]
    s = [inp[3], inp[4]]
    
    if ((s[0] and s[1]) or (a[0] and a[1])):
        return ['#', '#', '#', '#']
    
    a = conv_bin(a)
    s = conv_bin(s)
    
    # a += 1 # just because of the way we are encoding a and s
    # s += 1
    
    q = 0 # changed later
    o = [inp[3], inp[4]] # clone the current state -- moore machine
    
    if (b == 0):
        s -= a
    else:
        s += a
        
    # s -= 1 # re-encode into the 0 indexed states

    loop_val = 3
    s += loop_val * 10 # loop everything
    s %= loop_val
    
    if s == 0:
        q = [0, 0]
    elif s == 1:
        q = [0, 1]
    elif s == 2:
        q = [1, 0]
    else:
        print("ERROR, ERROR")
        
        
    out = [q[0], q[1], o[0], o[1]]
    return out
    
    


def cpy(lst):
    nw = []
    for i in range(len(lst)):
        nw.append(lst[i])
    return nw

def test(cur_inp, rem_inp):
    global table
    
    if (len(rem_inp) == 0):
        out = computeOut(cur_inp)
        for i in range(len(out)):
            cur_inp.append(out[i])
        table.append(cur_inp)
        return
        
    
    testA = cpy(cur_inp)
    testB = cpy(cur_inp)
    
    testA.append(0)
    testB.append(1)
    
    test_rem_inp = []
    for i in range(1, len(rem_inp)):
        test_rem_inp.append(rem_inp[i])
    test(testA, test_rem_inp)
    test(testB, test_rem_inp)
    
    
test([], inpts)
for line in table:
    str_out = ""
    for val in line:
        str_out += str(val) + ", "
    print(str_out)
        
# Generate the C boolean algebra using sum of products

def par(exp): # put an expression in parentheses
    return "(" + exp + ")"


c_code = ""
for i in range(len(outpt)):
    out_name = outpt[i]
    out_col = i + len(inpts)
    out_exp = "\t" + out_name + " = "
    first_1 = True
    for row in table:
        if (row[out_col] == 1):
            first_2 = True
            cur_exp = ""
            for j in range(len(inpts)):
                if (not first_2):
                    cur_exp += " && "
                else:
                    first_2 = False
                if (row[j] == 0):
                    cur_exp += par("!" + inpts[j])
                else:
                    cur_exp += inpts[j]
            if not first_1:
                out_exp += " || " + par(cur_exp)
            else:
                first_1 = False
                out_exp += par(cur_exp)
    c_code += out_exp + ";\n"

c_program = ""
with open("./states.h", 'r') as file:
    c_program = file.read()

if (WRITE_PROGRAM):
    parts = c_program.split("// SMLOGIC")
    if (len(parts) != 3):
        print("ERROR: Could not find flags in program")
        exit(-1)
    parts[1] = "\n" + c_code
    c_program = parts[0] + "// SMLOGIC" + parts[1] + "// SMLOGIC" + parts[2]
    
    with open("./states.h", 'w') as file:
        file.write(c_program)
        print("SUCCESS: C program written to file")
    


        