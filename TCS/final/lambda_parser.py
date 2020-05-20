import re

f = open("input.txt", "r")
f2 = open("output.txt", "w+")
exp = f.readline()

beta_red = 0
counter = 0
def check_lambda(exp):
    if (len(exp) > 0):
        if (exp[0] == '('):
            closing_brace_pos = find_closing_brace_position(exp)
            return check_lambda(exp[1:closing_brace_pos]) and check_lambda(exp[closing_brace_pos+1:])
        elif (exp[0] == '\\'):
            if ('.' in exp):
                dot_pos = find_dot_position(exp)
                global beta_red
                beta_red += 1
                return check_term(exp[1:dot_pos]) and check_lambda(exp[dot_pos+1:])
            else:
                return False
        else:
            return check_term(exp)

def check_term(exp):
    reg_ex = "^[A-Za-z0-9]*$"
    if re.match(reg_ex, exp):
        return True
    return False

def find_closing_brace_position(exp):
    count = -1
    index = 0
    while (count != 0):
        if count == -1:
            count = 0
        if (exp[index] == '('):
            count += 1
        if (exp[index] == ')'):
            count -= 1
        index += 1
    return index - 1

def find_dot_position(exp):
    return exp.find('.')

if (check_lambda(exp) == True):
    print("YES")
    print(str(beta_red))
else:
    print("NO")

f.close()
f2.close()
