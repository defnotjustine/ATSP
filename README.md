# TSP Problem - Implementacja trzech algorytmów

## Opis projektu

Celem projektu było zaimplementowanie i analiza trzech algorytmów rozwiązujących Problem Komiwojażera (TSP) — BruteForce, Random Search oraz Nearest Neighbour. Problem Komiwojażera polega na znalezieniu najkrótszej możliwej drogi, która odwiedza wszystkie miasta dokładnie raz, wracając do punktu początkowego.

Projekt polegał na:
- Implementacji algorytmów
- Testowaniu ich wydajności na różnych rozmiarach problemów
- Porównaniu wyników otrzymanych za pomocą różnych podejść

## Zrealizowane algorytmy

### 1. BruteForce (Algorytm Siłowy)
Algorytm BruteForce polega na wygenerowaniu wszystkich możliwych permutacji miast, a następnie obliczeniu łącznej odległości dla każdej permutacji. Algorytm ten gwarantuje znalezienie optymalnego rozwiązania, jednak jego złożoność czasowa jest wysoce nieefektywna, wynosząca O(n!).

**Zalety:**
- Gwarancja znalezienia optymalnego rozwiązania.
  
**Wady:**
- Bardzo wysoka złożoność obliczeniowa, niepraktyczna dla dużych problemów (n > 10).

### 2. Random Search (Algorytm Losowy)
Algorytm Random Search losowo generuje różne permutacje miast i oblicza ich odległość. Algorytm jest stosunkowo szybki, ale nie gwarantuje znalezienia najlepszego rozwiązania. Jego celem jest znalezienie wystarczająco dobrego rozwiązania w stosunkowo krótkim czasie.

**Zalety:**
- Szybkość obliczeń, szczególnie dla większych problemów.
  
**Wady:**
- Brak gwarancji optymalności rozwiązania.

### 3. Nearest Neighbour (Najbliższy Sąsiad)
Algorytm Nearest Neighbour działa na zasadzie lokalnej optymalizacji. Zaczyna od wybranego miasta i w każdej iteracji wybiera najbliższe miasto do odwiedzenia, aż wszystkie miasta zostaną odwiedzone. Algorytm jest szybki, ale również nie gwarantuje optymalnego rozwiązania.

**Zalety:**
- Szybkość obliczeń.
- Prosta implementacja.

**Wady:**
- Wynik może być daleki od optymalnego, zależny od wybranego punktu początkowego.
