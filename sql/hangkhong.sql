--3--
alter table chungnhan
add ghichu nvarchar(100)

--4--
select nv.ten, nv.manv, count(nv.manv) as 'Tong so may bay'
from nhanvien nv
join chungnhan cn on nv.manv = cn.manv
group by nv.ten, nv.manv
having count(nv.manv) = (
	select min(so_may_bay)
	from (
		select manv, count(mamb) as so_may_bay
		from chungnhan
		group by manv
	) as temp
)

--5--
select nv.manv, nv.ten
from nhanvien nv
join chungnhan cn on nv.manv = cn.manv
where cn.mamb in (747, 777)
group by nv.manv, nv.ten
having count(cn.mamb) =2

select manv
from chungnhan
where mamb in (747, 777)
group by manv
having count(mamb)=2

select c1.manv from chungnhan c1
join chungnhan c2 on c1.manv = c2.manv
where c1.mamb=747 and c2.mamb=777

SELECT MANV
FROM CHUNGNHAN
WHERE MAMB = '747'
INTERSECT
SELECT MANV
FROM CHUNGNHAN
WHERE MAMB = '777'

--6--
select mamb, sohieu
from maybay
where mamb not in (select distinct mamb from chungnhan)

--7--
select * from nhanvien
where luong> (select luong from nhanvien where manv='NV03')

--8--
select manv, ten
from nhanvien
where manv in (
	select manv
	from chungnhan
	group by manv
	having count(*) >=3
)

--9--
go
create proc ttinmaybay(@manv varchar(10))
as
select * from maybay
where mamb in (
	select mamb from chungnhan
	where manv=@manv
)

exec ttinmaybay 'NV05'

--10--
go
create trigger insert_slnvien
on nhanvien
for insert
as
declare @soluongnv int
select @soluongnv=count(*) from nhanvien
print 'Tong so dong trong bang la: '+str(@soluongnv)

----test----
select * from nhanvien
insert into nhanvien(manv, ten, luong)
values ('NV06', N'Dương Công An', '70000000')