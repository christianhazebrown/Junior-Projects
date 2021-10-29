import os
import Secndary_functions as Functions
import Database as D

from time import sleep



def main():
    while True:
        results = Functions.setup()
        if results == True:
            continue
        else:
            return 0
main()