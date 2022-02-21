#введення вхідних даних у файл
def fileInput(fileInName, mode):
    print("\nEnter text. Press Ctrl+S if finished.")
    fileIn = open(fileInName, mode)
    str = ''
    flag = True
    while flag:
        str = input()
        if str.find(chr(19)) != -1:
            flag = False
            str = str.replace(chr(19), '')
        if str != '':
            fileIn.write(str + '\n')
    fileIn.close()

#створення файлу відповідно поставленої задачі
def fileGen(fileInName, fileOutName, word):
    fileIn = open(fileInName, 'rt')
    fileOut = open(fileOutName, 'wt')
    line = fileIn.readline()
    while line:
        if lineCheck(line, word):
            fileOut.write(line)  
        line = fileIn.readline()
    fileIn.close()
    fileOut.close()

#перевірка рядку на наявність слова
def lineCheck(line, word):
    for w in line.split():
        if w == word or (w.find(word) != -1 and not w[-1].isalpha()):
            return True
    return False

#виведення даних із файлу
def fileOutput(fileName):
    print("\nFile {}:".format(fileName))
    fread = open(fileName, 'rt')
    print(fread.read())
    fread.close()

#запит користувача щодо додавання даних до файлу
def fileAdd(fileInName):
    check = input("Write + if you want to continuo or - to stop: ")
    if check == '+':
        fileInput(fileInName, "at")
        return True
    return False

#відображення статистики файлу
import os.path, time
def fileStat(fileName):
    print(fileName, 'stats:')
    print("Created:", time.ctime(os.path.getctime(fileName)))
    print("Size:", os.path.getsize(fileName), 'bytes')

