import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from keras.models import Sequential
from keras.layers import Conv2D, Flatten, Dense, MaxPooling2D, AveragePooling2D, Flatten
from keras.optimizers import Adam
from keras.datasets import fashion_mnist
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay
from keras.datasets import cifar10
from sklearn.datasets import load_iris
import pandas as pd
import numpy as np
from keras.regularizers import l2, l1
from keras.layers import Dense, BatchNormalization
from keras.layers import Dropout, GaussianNoise
from keras.layers import LayerNormalization
from keras.models import Sequential
from keras.optimizers import Adam, RMSprop, SGD
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
import pandas as pd
import numpy as np
from keras.regularizers import l2, l1
from keras.layers import Dense, BatchNormalization
from keras.layers import Dropout, GaussianNoise
from keras.layers import LayerNormalization
from keras.models import Sequential
from keras.optimizers import Adam, RMSprop, SGD
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from keras.layers import Conv2D, Flatten, Dense
from keras.models import Sequential
from keras.optimizers import Adam
from keras.datasets import mnist, fashion_mnist
import numpy as np
from keras.layers import Conv2D, Flatten,Dense, AveragePooling2D, MaxPooling2D
from keras.layers import Conv2D, MaxPooling2D
from tensorflow.keras.layers import concatenate
from keras.layers import Dense, Conv2D, MaxPooling2D,GlobalAveragePooling2D,Input, Flatten
from keras.models import Model
from keras.datasets import mnist
import numpy as np
import pandas as pd
# from tensorflow.keras.layers import Input, Conv2D, MaxPooling2D, Concatenate, Flatten, Dense
# from tensorflow.keras.models import Model
import tensorflow as tf
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense, Flatten, Conv2D, MaxPooling2D, Dropout
from tensorflow.keras.datasets import fashion_mnist
from tensorflow.keras import layers, models
from tensorflow.keras.layers import Input, Conv2D, MaxPooling2D, Concatenate, Flatten, Dense
from tensorflow.keras.models import Model

# <<< === Zadanie 1 ===>>> #

# 1 - ladowanie
(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()

# 2-  normalizowanie
x_train = x_train / 255.0
x_test = x_test / 255.0

# 5 - buduj model 4 warstyw,
model = Sequential([
    # jak nie flatten to moze conv ale jak inaczej nie wiem
    # Flatten(input_shape=(28, 28)),
    # znowu flatten po conv stwarza wiecej warstw
    Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)),
    Flatten(), # wejscie
    Dense(128, activation='relu'), # 4 razy ukryte
    Dense(64, activation='relu'),
    Dense(64, activation='relu'),
    Dense(32, activation='relu'),
    Dense(10, activation='softmax') # wyjscie
])

# 4 - kompilacka
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# 5 - trenowanie podsumowywwanie koniec
model.fit(x_train, y_train, epochs=5, validation_data=(x_test, y_test))
model.summary()  # nwm wsm czy potrzebne ale tak ladnie wyglada na koniec


# ===>>> Zadanie 2 <<<=== #

# 1 - ladowanie
# //conv 4D jest, Conv2 wuzyca blad inaczej xD
(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()
x_train = x_train / 255.0
x_test = x_test / 255.0
x_train = x_train.reshape(-1, 28, 28, 1)
x_test = x_test.reshape(-1, 28, 28, 1)

# 1 cd budowanie i trenowanie 6 warstw
# //konwulcyjna to chyba co drugia miaala inna
model = Sequential([
    Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)),
    MaxPooling2D((2, 2)),
    Conv2D(64, (3, 3), activation='relu'),
    MaxPooling2D((2, 2)),
    Conv2D(128, (3, 3), activation='relu'),
    Flatten(),
    Dense(128, activation='relu'),
    Dropout(0.5),
    Dense(64, activation='relu'),
    Dense(10, activation='softmax') # softmax na koniec bo tak
])

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5, validation_data=(x_test, y_test))

# 3 - ocenianie i podsumowywanie
strata, dokladnosc = model.evaluate(x_test, y_test)
print(f'Testowa strata: {strata}')
print(f'Testowa dokladnoscy: {dokladnosc}')
model.summary()


# <><><> Zadanie 3 <><><>
input_layer = Input(shape=(28, 28, 1))

# lewo
lewo = Conv2D(128, (3, 3), activation='relu', padding='same')(input_layer)
lewo = MaxPooling2D((2, 2), padding='same')(lewo)
lewo = Conv2D(64, (3, 3), activation='relu', padding='same')(lewo)

# prawo
prawo = Conv2D(256, (3, 3), activation='relu', padding='same')(input_layer)
prawo = MaxPooling2D((2, 2), padding='same')(prawo)

# zlaczenie dwoch
polaczone = Concatenate()([lewo, prawo])

splaszczone = Flatten()(polaczone)
dense9 = Dense(128, activation='relu')(splaszczone)
dense10 = Dense(10, activation='softmax')(dense9)

# Budowanie modelu
model = Model(inputs=input_layer, outputs=dense10)

# Kompilacja modelu
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# znowu nwm czy trzeba ale no
model.summary()
