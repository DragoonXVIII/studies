# -*- coding: utf-8 -*-
"""
json to yaml converter
"""
import yaml
import json


class ConvertJsonToYaml:
    @staticmethod
    def runBtoY(deserializeddata, destinationfilelocaiton):
        print("Loading JSON from object...")
        with open(destinationfilelocaiton, 'w', encoding='utf8') as f:
            yaml.dump(deserializeddata, f, allow_unicode=True)
        print("it is done")

    @staticmethod
    def runJtoY(jsonfilelocation: str, yamldestinationfilelocation: str, from_file: bool = True):
        print("loading JSON from file...")
        with open(jsonfilelocation, 'r', encoding='utf8') as f:
            data = json.load(f)

        ConvertJsonToYaml.runBtoY(data, yamldestinationfilelocation)