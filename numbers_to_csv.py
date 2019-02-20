import sys
import pandas as pd

DB = 'db/'

def read_util(fine_name):
	with open(DB+fine_name) as f:
		lines = f.readlines()

	return lines

def write_util(lines):
	with open('db.csv', 'w') as out:
		for l in lines:
			out.write(','.join(l.split())+'\n')

def convert(fine_name):
	lines = read_util(fine_name)
	write_util(lines)

def main():
	convert('db_only_numbers.txt')

if __name__ == '__main__':
	main()