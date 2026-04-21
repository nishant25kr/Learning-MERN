const books = [
    { title: 'Book One', genre: 'fiction', publish: 1981, edition: 2004 },
    { title: 'Book Two', genre: 'history', publish: 1992, edition: 2008 },
    { title: 'Book Three', genre: 'science', publish: 1999, edition: 2007 },
    { title: 'Book Four', genre: 'non-fiction', publish: 2001, edition: 2012 },
    { title: 'Book Five', genre: 'history', publish: 2005, edition: 2015 },
    { title: 'Book Six', genre: 'romance', publish: 2010, edition: 2020 },
    { title: 'Book Seven', genre: 'thriller', publish: 2015, edition: 2023 }
];

const mapedBooks = books.map((b)=>{
  console.log(b.title)
  console.log(b.genre)
})

const greaterThen2000 = books.filter( b => b.publish > 2000)

console.log(greaterThen2000);