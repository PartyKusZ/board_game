import random

# Losuję rozmiar listy 2D
rozmiar = random.randint(500,500)

# Tworzę listę 2D wypełnioną zerami
lista_2d = [[0 for _ in range(rozmiar)] for _ in range(rozmiar)]

# Tworzę listę liczb
liczby = [0, 1, 2, 6, 9]

# Wypełniam listę 2D
for i in range(rozmiar):
    for j in range(rozmiar):
        # Losuję liczbę z listy
        liczba = random.choice(liczby)
        # Sprawdzam czy liczba to 1 lub 2
        if liczba in [1, 2] and liczba in liczby:
            # Jeżeli tak, usuwam tę liczbę z listy liczb
            liczby.remove(liczba)
        # Wpisanie wylosowanej liczby do listy 2D
        lista_2d[i][j] = liczba

ownership = ["P","E"]
units_name = ["K", "S", "A", "P", "C", "R", "W"]
units = []
id = 0
for i in range(rozmiar):
    for j in range(rozmiar):
        if(lista_2d[i][j] != 9 and lista_2d[i][j] != 1 and lista_2d[i][j] != 2):
            if(j % 10 == 0 ):
                units.append(random.choice(ownership)+ " " + random.choice(units_name)+ " " + str(id)+ " " + str(j)+ " " + str(i)+ " " + str(15))
                id += 1

        if id == 998:
            break
    if id == 998:
        break


# Wyświetlam listę 2D
for row in lista_2d:
    for i in row:
        print(i, sep="", end="")
    print("\n",end="")

print("------------------")
for unit in units:
    print(unit)