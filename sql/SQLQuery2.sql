create database HangKhong

use HangKhong

create table maybay
(
	mamb int primary key,
	sohieu varchar(100) unique,
	tambay int check(tambay>0)
)

create table nhanvien
(
	manv varchar(5) primary key,
	ten nvarchar(100),
	luong varchar(20)
)

create table chungnhan
(
	manv varchar(5),
	mamb int
	primary key(manv, mamb)
)

alter table chungnhan
add
	constraint fk_cn_nv
	foreign key (manv)
	references nhanvien(manv),
	constraint fk_cn_mb
	foreign key (mamb)
	references maybay(mamb)

insert into maybay(mamb, sohieu, tambay) 
values
(747, 'Boeing 747 - 400', 13488),
(737, 'Boeing 737 - 800', 5413);

insert into nhanvien(manv, ten, luong)
values
('NV01', N'Nguyễn Đắc Đăng', '5000000'),
('NV02', N'Nguyễn Minh Long', '6000000');

insert into chungnhan(manv, mamb)
values
('NV01', 747),
('NV01', 340),
('NV02', 777),
('NV02', 737);

select * from maybay
select * from nhanvien
select * from chungnhan