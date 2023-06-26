import random

# Losuję rozmiar listy 2D
rozmiar = random.randint(5,6)

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

# Wyświetlam listę 2D
for row in lista_2d:
    for i in row:
        print(i, sep="", end="")
    print("\n")