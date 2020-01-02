import pandas as pd
import numpy as np
import time
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings('ignore')
import seaborn as sns
sns.set()
import re
import os
import datetime



def read_page():
    import urllib.request

    url = 'http://www.resultadosmegasena.com.br/resultados-anteriores'
    #url = 'http://www.google.com'
    response = urllib.request.urlopen(url)
    data = response.read()      # a `bytes` object
    #text = data.decode() # a `str`; this step can't be used if data is binary

    print(response)
    print(data)
    #print(text)


def read(data_file, sep=','):
    try:
        df = pd.read_csv(data_file, sep)
        return df
    except Exception as e:
        print(e)


def page_to_csv():
    pass


def print_all_avg(df):
    print(df['n1'].mean())
    print(df['n2'].mean())
    print(df['n3'].mean())
    print(df['n4'].mean())
    print(df['n5'].mean())
    print(df['n6'].mean())


def main():
    df = read('db.csv')
    print_all_avg(df)


if __name__ == '__main__':
    main()
