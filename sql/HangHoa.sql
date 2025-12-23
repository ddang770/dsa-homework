create table SanPham
(
	masp varchar(5) primary key,
	tensp nvarchar(30) unique,
	kichthuoc varchar(5) check(kichthuoc in('S', 'M','L','XL')),
	mausac nvarchar(20)
)

create table NhaSanXuat
(
	mansx varchar(10) primary key,
	tennsx nvarchar(30),
	diachi nvarchar(30)
)

create table CungCap
(
	mansx varchar(10),
	masp varchar(5),
	ngay varchar(20),
	soluong int check(soluong>0)
)

ALTER TABLE CungCap
ADD
    CONSTRAINT fk_cc_nsx FOREIGN KEY (mansx) REFERENCES NhaSanXuat(mansx),
    CONSTRAINT fk_cc_sp FOREIGN KEY (masp) REFERENCES SanPham(masp);

select * from CungCap

insert into SanPham(masp, tensp, kichthuoc, mausac)
values ('001', N'Áo cộc họa tiết', 'S', N'Xanh'),
('002', N'Quần dài trơn', 'S', N'Be'),
('003', N'Quần đùi trên gối', 'M', N'Xanh'),
('004', N'Quần ngố họa tiết', 'L', N'Đen'),
('005', N'Quần bó ống', 'XL', N'Đen'),
('006', N'Áo cộc trơn', 'M', N'Tím')

insert into NhaSanXuat(mansx, tennsx, diachi)
values ('SX01', N'Thành Đông', N'Hà Nội'),
('SX02', N'Hải Hà', N'Hưng Yên'),
('SX03', N'Chiến Thắng', N'Hải Phòng'),
('SX04', N'Hưng Bền', N'Hà Nội')

insert into CungCap(mansx, masp, ngay, soluong)
values ('SX01', '001', '1/1/2024', 50),
('SX01', '006', '3/20/2024', 20),
('SX02', '002', '1/1/2024', 10),
('SX02', '003', '1/25/2024', 30),
('SX03', '002', '1/1/2024', 40),
('SX03', '005', '3/22/2024', 50),
('SX04', '006', '1/19/2024', 90),
('SX04', '003', '1/2/2024', 100)

SELECT nsx.TENNSX, SUM(cc.soluong) AS TongSoLuong
FROM CUNGCAP cc
JOIN NHASANXUAT nsx ON cc.mansx = nsx.MANSX
GROUP BY nsx.TENNSX
HAVING SUM(cc.soluong) > (
    SELECT SUM(soluong) 
    FROM CUNGCAP 
    WHERE mansx = 'SX01'
);

--Truy van--
--4--
select cc.mansx, sum(cc.soluong) as 'tong so sp'
from cungcap cc
group by cc.mansx
having sum(cc.soluong) > (select sum(soluong) from CungCap where mansx='SX01')

--5--
select * from SanPham
where masp not in (select distinct masp from CungCap)

--6--
select * from SanPham
where tensp like N'Q%' and kichthuoc='S'

--7--
select * from SanPham where masp in (select masp from CungCap where mansx='SX01')

--8--
select nsx.tennsx, sum(cc.soluong) as 'Tong so luong'
from NhaSanXuat nsx
join CungCap cc on cc.mansx=nsx.mansx
group by nsx.tennsx

--9--
select sp.masp, sp.tensp, count(sp.masp) as 'so lan cung cap' from SanPham sp
join CungCap cc on sp.masp=cc.masp
group by sp.masp, sp.tensp
having count(sp.masp) = (
	select max(so_luong_nsx)
	from (
		select masp, count(masp) as so_luong_nsx
		from CungCap
		group by masp
	) as temp
)

select top(1) with ties sp.masp, sp.tensp, count(cc.masp) as solancungcap
from SanPham sp
join CungCap cc on cc.masp=sp.masp
group by sp.masp, sp.tensp
order by solancungcap desc