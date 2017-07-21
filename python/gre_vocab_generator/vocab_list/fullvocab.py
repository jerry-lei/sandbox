import os
import re

listOfWords = []

for c1 in range(1,7):
    filesrcname = "vocab" + str(c1) + ".txt"
    filesource = open(filesrcname,"r")
    FullFile = filesource.read()
    FileSplit = FullFile.splitlines()
    for line in FileSplit:
        line = re.sub('\(([^\)]+)\)', '', line)
        line = re.sub('\n', '', line)
        line = re.sub('\r', '', line)
        line = re.sub(' +', ' ', line)
        line = line.encode('ascii', 'ignore')
        currentLineWords = line.split(' ')
        for wordInLine in currentLineWords:
            if len(wordInLine) > 3:
                listOfWords.append(wordInLine)

for word in listOfWords:
    print word
