#! /usr/bin/python3

from mrjob.job import MRJob

class MyMRJob(MRJob):
    def mapper(self, _, line):
        company, price, date = line.split(',')

        # Es posible comparar enteros alfanuméricamente y da el
        # resultado correcto. Sin embargo, estas líneas permiten
        # ignorar el encabezado del csv
        try:
            price = int(price)
        except ValueError:
            pass
        else:
            yield company, (price, date)

    def reducer(self, company, pricedates):
        min_price, min_date = next(pricedates)
        max_price, max_date = min_price, min_date

        for price, date in pricedates:
            if price < min_price:
                min_price, min_date = price, date
            
            if price > max_price:
                max_price, max_date = price, date

        yield company, (min_date, max_date)

if __name__ == '__main__':
    MyMRJob.run()
