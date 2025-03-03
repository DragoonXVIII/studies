"""
serialize json
"""
import json


class SerializeJson:

    @staticmethod
    def run(deserializeddata, filelocation):
        print("let's serialize something")
        lst = []

        # TODO – do modyfikacji
        for dep in deserializeddata.data:
            lst.append({
                "Kod_TERYT": dep['Kod_TERYT'],
                "Województwo": dep['Województwo'],
                "Powiat": dep.get('Powiat', 'Brak danych'),
                "typ_JST": dep['typ_JST'],
                "nazwa_urzędu_JST": dep['nazwa_urzędu_JST'],
                "miejscowość": dep['miejscowość'],
                "telefon_z_numerem_kierunkowym": str(dep['telefon kierunkowy']) + str(dep['telefon'])
            })

        jsontemp = {"departaments": lst}
        with open(filelocation, 'w', encoding='utf-8') as f:
            json.dump(jsontemp, f, ensure_ascii=False)
