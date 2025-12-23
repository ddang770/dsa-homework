create table detai(
	madt varchar(10) primary key,
	tendt nvarchar(50),
	kinhphi float,
	noithuctap nvarchar(20)
)

create table giangvien(
	magv varchar(10) primary key,
	hotengv nvarchar(50),
	luong float,
	makhoa varchar(10)
)

create table huongdan(
	masv varchar(10),
	madt varchar(10),
	magv varchar(10),
	ketqua float
	primary key(masv, madt, magv)
)

create table khoa(
	makhoa varchar(10) primary key,
	tenkhoa nvarchar(50),
	dienthoai varchar(20)
)

create table sinhvien(
	masv varchar(10) primary key,
	hoten nvarchar(50),
	makhoa varchar(10),
	namsinh int,
	quequan nvarchar(20)
)

alter table giangvien
add
	constraint gv_makhoa
	foreign key (makhoa)
	references khoa(makhoa)

alter table huongdan
add
	constraint hd_masv
	foreign key (masv)
	references sinhvien(masv),
	constraint hd_madt
	foreign key (madt)
	references detai(madt),
	constraint hd_magv
	foreign key (magv)
	references giangvien(magv)

alter table sinhvien
add
	constraint sv_makhoa
	foreign key (makhoa)
	references khoa(makhoa)

insert into detai(madt, tendt, kinhphi, noithuctap)
values ('DT01', N'Hệ thống quản lý', 5000000.00, N'Hà Nội'),
('DT02', N'Phân tích dữ liệu', 8000000.00, N'Đà Nẵng'),
('DT03', N'Kế toán doanh nghiệp', 3000000.00, N'Hải Phòng'),
('DT04', N'Thiết kế website', 7000000.00, N'Hà Nội'),
('DT05', N'Lập trình ứng dụng', 6000000.00, N'HCM')

insert into giangvien(magv, hotengv, luong, makhoa)
values ('GV01', N'Nguyễn Văn An', 15000000.00, 'CNTT'),
('GV02', N'Lê Thị Bình', 12000000.00, 'CNTT'),
('GV03', N'Trần Văn Cường', 18000000.00, 'KT'),
('GV04', N'Phạm Thị Dung', 14000000.00, 'QTKD'),
('GV05', N'Hoàng Văn Đạt', 20000000.00, 'XD')

insert into khoa(makhoa, tenkhoa, dienthoai)
values ('CK', N'Cơ khí', '0244567890'),
('CNTT', N'Công nghệ thông tin', '0241234567'),
('KT', N'Kinh tế', '0242345678'),
('QTKD', N'Quản trị kinh doanh', '0243456789'),
('XD', N'Xây dựng', '0245678901')

insert into sinhvien(masv, hoten, makhoa, namsinh, quequan)
values ('SV01', N'Nguyễn Văn Nam', 'CNTT', 2003, N'Hà Nội'),
('SV02', N'Lê Thị Hoa', 'CNTT', 2002, N'Đà Nẵng'),
('SV03', N'Trần Văn Hùng', 'KT', 2001, N'Hải Phòng'),
('SV04', N'Phạm Thu Hằng', 'QTKD', 2003, N'Hà Nam'),
('SV05', N'Hoàng Văn Khánh', 'XD', 2000, N'Nghệ An')

insert into huongdan(masv, madt, magv, ketqua)
values ('SV01', 'DT01', 'GV01', 9.0),
('SV02', 'DT02', 'GV02', 7.5),
('SV03', 'DT03', 'GV03', NULL),
('SV04', 'DT04', 'GV04', 8.0),
('SV05', 'DT05', 'GV05', NULL)

select * from sinhvien
--delete from khoa

--1--
select * from giangvien
where magv in (
	select hd.magv from huongdan hd
	join detai dt on hd.madt=dt.madt
	where dt.noithuctap=N'Hà Nội'
)

--2--
select top(1) with ties gv.hotengv, k.tenkhoa
from giangvien gv
join khoa k on gv.makhoa=k.makhoa
order by gv.luong desc

select gv.hotengv, k.tenkhoa
from giangvien gv
join khoa k on gv.makhoa=k.makhoa
where gv.luong = (select max(luong) from giangvien)

--3--
select tendt from detai
where madt in (
	select hd.madt from huongdan hd
	join giangvien gv on hd.magv=gv.magv
	where gv.hotengv != N'Nguyễn Văn An'
)

--4--
select hotengv from giangvien
where magv in (
	select magv from huongdan
	group by magv
	having count(masv)>0
)

--5--
select * from sinhvien
where masv in (
	select distinct masv from huongdan
)

--6--

--7--
select * from sinhvien
where masv in (
	select top(1) with ties masv from huongdan
	order by ketqua desc
)

--8--
select sv.hoten, gv.hotengv, dt.tendt from huongdan hd
join detai dt on hd.madt=dt.madt
join giangvien gv on gv.magv=hd.magv
join sinhvien sv on sv.masv=hd.masv

--9--
select * from giangvien
where luong>(select luong from giangvien where hotengv=N'Nguyễn Văn An')

--10--
go
create proc update_tengv(@hotengv_doi nvarchar(50), @hotengv nvarchar(50))
as
update giangvien
set hotengv=@hotengv
where hotengv=@hotengv_doi

--exec update_tengv N'Hoàng Văn Đạt', N'Nguyễn Văn Đạt'
--select * from giangvien

--11--
go
create proc add_giangvien(@magv varchar(10), @hotengv nvarchar(50), @luong float, @makhoa varchar(10))
as
insert into giangvien
values (@magv, @hotengv, @luong, @makhoa)

--exec add_giangvien 'GV06', N'Nguyễn Văn B', 50000000, 'CNTT'
--select * from giangvien

--12--
go
create proc gvchuatgiadetai
as
select hotengv from giangvien
where magv not in (select distinct magv from huongdan)

--exec gvchuatgiadetai

--13--
go
create proc get_ttindetai(@tendt nvarchar(50))
as
select * from detai
where tendt=@tendt

--exec get_ttindetai N'Hệ thống quản lý'