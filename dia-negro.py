#! /usr/bin/python3

from mrjob.job import MRJob
from mrjob.step import MRStep

class MyMRJob(MRJob):
    def mapper(self, _, line):
        company, price, date = line.split(',')

        try:
            price = float(price)
        except ValueError:
            pass
        else:
            yield company, (price, date)

    def reducer1(self, company, pricedates):
        min_price, min_date = next(pricedates)

        for price, date in pricedates:
            if price < min_price:
                min_price, min_date = price, date

        yield min_date, 1

    def reducer2(self, date, counts):
        yield date, sum(counts)

    def steps(self):
        return [MRStep(mapper=self.mapper, reducer=self.reducer1),
                MRStep(reducer=self.reducer2)]

if __name__ == '__main__':
    MyMRJob.run()
