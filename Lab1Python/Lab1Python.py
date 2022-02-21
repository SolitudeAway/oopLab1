import module1 #включення користувацької бібліотеки

word = input("Enter the word: ")                        #слово для виконання поставленої задачі
fileInName = input("Enter the name of input file: ")    #введення назви файлу ввідних даних
fileOutName = 'output.txt'                              #назва файлу вихідних даних
fileLib.fileInput(fileInName, "wt")                     #введення даних у файл ввідних даних
fileLib.fileGen(fileInName, fileOutName, word)          #створення файлу вихідних даних
fileLib.fileOutput(fileInName)                          #виведення файлу ввідних даних
fileLib.fileOutput(fileOutName)                         #виведення файлу вихідних даних
fileLib.fileStat(fileOutName)                           #відображення статистики файлу
while fileLib.fileAdd(fileInName):                      #поки користувач бажає додати дані до файлу ввідних даних
    fileLib.fileGen(fileInName, fileOutName, word)          #створення файлу вихідних даних
    fileLib.fileOutput(fileInName)                          #виведення файлу ввідних даних
    fileLib.fileOutput(fileOutName)                         #виведення файлу вихідних даних
