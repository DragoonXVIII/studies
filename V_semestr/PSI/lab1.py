import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data_excel = pd.read_excel("dane_w_ekselu.xlsx")
data_array = data_excel.to_numpy()
values = data_excel.values

zero_counts = (data_array == 0).sum(axis=0) # Suma zer w kolumnach
max_zero_count = np.max(zero_counts) # Maksymalna liczba zer
# columns_with_most_zeros = np.where(zero_counts == max_zero_count)[0] # Indeksy kolumn z największą liczbą zer
columns_with_most_zeros = data_excel.columns[np.where(zero_counts == max_zero_count)[0]]  # Nazwy kolumn z największą liczbą zerprint(f"Najwięcej zer ({max_zero_count}) znajduje się w kolumnach: {columns_with_most_zeros.tolist()}")
print(f"Najwięcej zer ({max_zero_count}) znajduje się w kolumnach: {columns_with_most_zeros}")



print(f"Najwięcej zer ({max_zero_count}) znajduje się w kolumnach: {columns_with_most_zeros}")
"""
data_excel = pd.read_excel("dane_w_ekselu.xlsx")
data_array = data_excel.to_numpy()

even_rows = data_array[::2, :]  # od 0, krok 2 (wybór parzystych wierszy)
odd_rows = data_array[1::2, :]  # od 1, krok 2 (wybór nieparzystych wierszy)
min_rows = min(even_rows.shape[0], odd_rows.shape[0])

even_rows = even_rows[:min_rows, :]
odd_rows = odd_rows[:min_rows, :]

difference_array = even_rows - odd_rows
print("Tablica różnicy:", difference_array)

# srednia
mean_value = data_array.mean()

std_value = data_array.std()

normalized_array = (data_array - mean_value) / std_value
print("Tablica różnicy - średnia:", difference_array)

mean_columns = data_array.mean(axis=0)
std_columns = data_array.std(axis=0)
std_columns += np.spacing(std_columns)
normalized_array = (data_array - mean_columns) / std_columns
print("Znormalizowana tablica - średnie kolumny:", normalized_array)

coefficient_of_variation = mean_columns / std_columns
print("Współczynnik zmienności dla każdej kolumny:", coefficient_of_variation)

max_cv_index = np.argmax(coefficient_of_variation)
print(f"Kolumna o największym współczynniku zmienności: {max_cv_index+1}")
print(f"Największy współczynnik zmienności: {coefficient_of_variation[max_cv_index]}")

zero_counts = (data_array == 0).sum(axis=0)
max_zero_count = np.max(zero_counts)
columns_with_most_zeros = np.where(zero_counts == max_zero_count)[0]

print(f"Najwięcej zer ({max_zero_count}) znajduje się w kolumnach: {columns_with_most_zeros}")

"""
"""
num_columns = data_array.shape[1]
num_even_columns = (num_columns + 1) // 2  
num_odd_columns = num_columns // 2  

even_index_sum = data_array[:, ::2].sum(axis=0)[:num_even_columns]  # Suma pozycji parzystych dla każdej kolumny
odd_index_sum = data_array[:, 1::2].sum(axis=0)[:num_odd_columns]   # Suma pozycji nieparzystych dla każdej kolumny

if len(even_index_sum) != len(odd_index_sum):
    min_length = min(len(even_index_sum), len(odd_index_sum))
    even_index_sum = even_index_sum[:min_length]
    odd_index_sum = odd_index_sum[:min_length]
columns_with_greater_even_sum = even_index_sum > odd_index_sum
result_columns = data_excel.columns[columns_with_greater_even_sum]
print(f"Kolumny, w których suma elementów na pozycjach parzystych jest większa od sumy elementów na pozycjach nieparzystych: {result_columns.tolist()}")
"""
"""
x = np.arange(-5, 5, 0.01)
y = np.tanh(x)

plt.plot(x, y, label='funkcja')
plt.title('Wykres funkcji:')
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black',linewidth=0.5, ls='--')  # Linia pozioma y=0
plt.axvline(0, color='black',linewidth=0.5, ls='--')  # Linia pionowa x=0
plt.grid()
plt.legend()
plt.show()

y = 1/(1+np.exp(-x))
y = np.where(x > 0, x, 0)
"""

"""
# Tworzenie danych za pomocą numpy
data = np.random.randn(100)  # 100 losowych wartości

# Tworzenie DataFrame z pandas
df = pd.DataFrame(data, columns=['Random Data'])

# Wyświetlenie pierwszych kilku wierszy dla podglądu
print(df.head())

# Wykres za pomocą matplotlib
plt.figure(figsize=(10,6))
plt.plot(df, label='Random Data')
plt.title('Wykres losowych danych')
plt.xlabel('Indeks')
plt.ylabel('Wartości')
plt.legend()
plt.grid(True)
plt.show()
"""