# 2.1-2.5
"""
from deserialize_json import DeserializeJson
from serialize_json import SerializeJson
from convert_json_to_yaml import ConvertJsonToYaml \

print("hey, it's me - Python!")


newDeserializator = DeserializeJson('Assets/data.json')
newDeserializator.somestats()
SerializeJson.run(newDeserializator,'Assets/data_mod.json')
ConvertJsonToYaml.runBtoY(newDeserializator, 'Assets/data_mod.yaml')
ConvertJsonToYaml.runJtoY("Assets/data.json", "Assets/data_mod_2.yaml", True)
"""

# 2.6.2
"""
import yaml
from deserialize_json import DeserializeJson
from serialize_json import SerializeJson
from convert_json_to_yaml import ConvertJsonToYaml

print("hey, it's me - Python!")

# Odczyt danych konfiguracyjnych z pliku YAML
with open('Assets/basic_config.yaml', encoding="utf8") as tempconffile:
    confdata = yaml.load(tempconffile, Loader=yaml.FullLoader)

source_file_path = confdata['paths']['source_folder'] + confdata['paths']['json_source_file']
output_json_path = confdata['paths']['source_folder'] + confdata['paths']['json_destination_file']
output_yaml_path = confdata['paths']['source_folder'] + confdata['paths']['yaml_destination_file']

newDeserializator = DeserializeJson(source_file_path)
newDeserializator.somestats()
SerializeJson.run(newDeserializator, output_json_path)
ConvertJsonToYaml.runBtoY(newDeserializator, output_yaml_path)
ConvertJsonToYaml.runJtoY(source_file_path, output_yaml_path)
"""

# 2.6.4
import yaml
from deserialize_json import DeserializeJson
from serialize_json import SerializeJson
from convert_json_to_yaml import ConvertJsonToYaml

print("hey, it's me - Python!")

with open('Assets/advanced_config.yaml', encoding="utf8") as tempconffile:
    confdata = yaml.load(tempconffile, Loader=yaml.FullLoader)


source_file_path = confdata['paths']['source_folder'] + confdata['paths']['json_source_file']
output_json_path = confdata['paths']['source_folder'] + confdata['paths']['json_destination_file']
output_yaml_path = confdata['paths']['source_folder'] + confdata['paths']['yaml_destination_file']


if confdata['serialization']['source'] == "file":
    newDeserializator = DeserializeJson(source_file_path)
elif confdata['serialization']['source'] == "object":
    newDeserializator = DeserializeJson(confdata['paths']['json_source_file'])  # Zastąp to odpowiednim obiektem

operations = confdata['serialization']['operations']
for operation in confdata['serialization']['order']:
    if operation == "somestats" and "somestats" in operations:
        newDeserializator.somestats()
    elif operation == "serialize_json" and "serialize_json" in operations:
        SerializeJson.run(newDeserializator, output_json_path)
    elif operation == "convert_json_to_yaml" and "convert_json_to_yaml" in operations:
        ConvertJsonToYaml.runJtoY(source_file_path, output_yaml_path)

