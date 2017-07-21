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
    writingFile.write("#### " + item + '\n')
    writingFile.close()
    counter+=1
