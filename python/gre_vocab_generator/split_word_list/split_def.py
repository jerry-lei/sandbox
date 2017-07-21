import math

fileWords = open("full_definitions.txt","r")
allText = fileWords.read()
ListOfWords = allText.split('\n\n')

NUMBEROFWORDS = 50

counter = 0
for item in ListOfWords:
    fileNumber = math.floor(counter/NUMBEROFWORDS)
    fileDest = "split_words/word_cluster" + str(int(fileNumber)) + '.md'
    writingFile = open(fileDest,"a")
    #reformat text block
    splitItem = item.split('\n')
    newString = "#### " + splitItem[0] + '\n'
    for c1 in xrange(1,len(splitItem)):
        splitItem[c1].replace('\t','')
        newString += '`' + splitItem[c1] + '`' + '\n'
    writingFile.write(newString + '\n')
    writingFile.close()
    counter+=1
