import pandas as pd

def read_db(file):
	df = pd.read_csv(file)
	return df

def preprocess(df):
	df = df.loc[:, ~df.columns.str.contains('^Unnamed')]
	df = df.dropna()


def main():
	df = read_db('db.csv')
	
	preprocess(df)

	print(df.describe())

if __name__ == '__main__':
	main()