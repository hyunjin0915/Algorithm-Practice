-- 코드를 입력하세요
SELECT book_id, author_name, DATE_FORMAT(PUBLISHED_DATE,'%Y-%m-%d') from book, author 
where book.author_id = author.author_id and category = '경제' order by published_date ;