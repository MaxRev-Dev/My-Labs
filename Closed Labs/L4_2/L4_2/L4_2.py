

class BookReview:
    def __init__(self, *args):
        self.Content = args[0] 

    Content = ""
    def __repr__(self):
        return "'%s'" % (self.Content)
    
class Book:
   def __init__(self, *args, **kwargs):

       self.reviews = []
        
       if kwargs is not None:
           self.author = kwargs['author']
           self.name = kwargs['name']
           self.genre = kwargs['genre']
           self.publisher = kwargs['pub']
           self.publishYear = kwargs['year']
           self.reviews = kwargs['reviews'] 
       pass

   author = ""
   publishYear = -1
   genre = ""
   publisher = ""
   name = ""
   reviews = [None]


   def formated(self):
       return "Author: %s\nName: %s\nYear: %s\nPublisher:%s\nReviews: %s" % (self.author,self.name,self.publishYear,self.publisher,"".join(["\n-- %s" % i for i in self.reviews]))
   def __eq__(self, value):
      return (self.author == value.author and self.genre == self.genre and self.name == name and self.publishYear == value.publishYear)
   def __str__(self):
       return self.formated()
   def __repr__(self):
      return self.formated()

   def append(self, item):
        if isinstance(item, BookReview):
            super(BookReview, self).append(item)
        else:
            raise ValueError('BookReview items allowed only')

   def insert(self, index, item):
        if isinstance(item, BookReview):
            super(BookReview, self).insert(index, item)
        else:
            raise ValueError('Reviews allowed only')
         
reviews = [BookReview("John: Such an amazing story!"),BookReview("Bob: It was an exciting reading!")]

book1 = Book(author='James Aldridge',
                name = 'Signed with Their Honour', 
                genre ='novel',
                pub = 'Brown, Little & Co',
                year = 1942, reviews=reviews)

book2 = Book(author='Agatha Christie',
                name = 'Evil Under the Sun', 
                genre ='chrime novel',
                pub = 'Collins Crime Club',
                year = 1941, reviews=reviews) 

print("".join("\n%s\n" % i for i in [
    book1,
    book2 , 
    'Books are equal: %s' % (book1 == book2)]))

