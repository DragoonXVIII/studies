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

# FINAL
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
fromfile = confdata['serialization']['convert_json_to_yaml']['from_file']
fromobject = confdata['serialization']['convert_json_to_yaml']['from_object']


print(fromfile)
print(fromobject)

newDeserializator = DeserializeJson(source_file_path)

operations = confdata['serialization']['operations']
for operation in confdata['serialization']['order']:
    if operation == "somestats" and "somestats" in operations:
        newDeserializator.somestats()
    elif operation == "serialize_json" and "serialize_json" in operations:
        SerializeJson.run(newDeserializator, output_json_path)
    elif operation == "convert_json_to_yaml" and "convert_json_to_yaml" in operations:
        if fromfile:
            print("from file")
            ConvertJsonToYaml.runJtoY(source_file_path, output_yaml_path)
        if fromobject:
            print("from object")
            ConvertJsonToYaml.runBtoY(newDeserializator.data, output_yaml_path)

        # ConvertJsonToYaml.runJtoY(source_file_path, output_yaml_path)



# dodatkowe na 5
"""
import os
import xml.etree.ElementTree as ET
import json

def load_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        return file.read()

def xml_to_json(xml_data):

    root = ET.fromstring(xml_data)


    def xml_element_to_dict(element):
        data = {}
        for child in element:
            data[child.tag] = xml_element_to_dict(child) if len(child) > 0 else child.text
        return data


    xml_dict = xml_element_to_dict(root)

    json_data = json.dumps(xml_dict, indent=4)
    return json_data

def json_to_xml(json_data):

    data = json.loads(json_data)


    def dict_to_xml(tag, d):

        element = ET.Element(tag)
        for key, value in d.items():
            if isinstance(value, dict):
                element.append(dict_to_xml(key, value))
            else:
                child = ET.SubElement(element, key)
                child.text = str(value)
        return element

    root_tag = list(data.keys())[0]  #glowny tag jako pierwszy klucz
    root = dict_to_xml(root_tag, data[root_tag])

    return ET.tostring(root, encoding='unicode', method='xml')


xml_file_path = os.path.join('Assets', 'dataZ.xml')
json_file_path = os.path.join('Assets', 'dataZ.json')


xml_data = load_file(xml_file_path)
json_data = load_file(json_file_path)


json_result = xml_to_json(xml_data)
print("XML to JSON:\n", json_result)


xml_result = json_to_xml(json_data)
print("\nJSON to XML:\n", xml_result)

"""