#! /usr/bin/python3

from mrjob.job import MRJob

class MyMRJob(MRJob):
    def mapper(self, _, line):
        company, price, date = line.split(',')

        try:
            price = float(price)
        except ValueError:
            pass
        else:
            yield company, (price, date)

    def reducer(self, company, pricedates):
        dateprices = []

        for price, date in pricedates:
            dateprices.append((date, price))

        dateprices.sort()

        increasing = True
        _, pprice = dateprices[0]

        for date, price in dateprices:
            if price < pprice:
                increasing = False
            pprice = price

        yield company, increasing

if __name__ == '__main__':
    MyMRJob.run()
