#testing the concept

import re

#file_name = raw_input("Enter textfile name (ex. hamlet.txt): ")

def app(f_name):
    fd = open(f_name, 'r')
    fd = fd.read()
    lines = fd.split('\n')
    c1 = 0
    while(c1 < len(lines)):
        #lines[c1] = re.sub('[^0-9a-zA-Z]+', '', lines[c1])
        if len(lines[c1]) == 0:
            lines.pop(c1)
        c1+=1
    return lines


def game():
    lines = app('hamlet.txt')
    current_line=0
    while current_line < len(lines):
        if current_line == 0:
            guess = raw_input("First line: ")
            if re.sub('[^0-9a-zA-Z]+','',guess) == re.sub('[^0-9a-zA-Z]+','',lines[current_line]):
                current_line += 1
        elif current_line > 0:
            print "Previous line: " + lines[current_line-1]
            guess = raw_input("Line: ")
            if re.sub('[^0-9a-zA-Z]+','',guess) == re.sub('[^0-9a\-zA-Z]+','',lines[current_line]):                                                 current_line += 1


game()

