wordList, tempList = list(), list()
for _ in range(int(input())):
    tempList.extend(input().strip().lower().split(' '))
    for word in tempList:
        word = word.replace('\n', '')
        word = word.replace('\'', '')
        word = word.replace('.', '')
        word = word.replace(',', '')
        word = word.replace(':', '')
        word = word.replace(';', '')
        if len(word) > 0 and word not in wordList:
            wordList.append(word)
    tempList.clear()
wordList.sort()
print(len(wordList))
for word in wordList:
    print(word)
