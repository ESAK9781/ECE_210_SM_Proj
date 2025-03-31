# Generate the table
inpts = ['a2', 'a1', 'b', 's2', 's1']
outpt = ['q2', 'q1', 'o2', 'o1']
table = []

def conv_bin(bin_l):
    cur_place = 1
    for i in range(len(bin_l)):
        

def computeOut(inp):
    


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



table = [
    ['a2', 'a1', 'b', ]   
]

outputs = ''

print("Hello World");