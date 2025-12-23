create database QLDiem

use QLDiem

create table sinhvien
(
	masv varchar(10) primary key,
	hoten nvarchar(40) not null,
	gioitinh nvarchar(4) check (gioitinh in(N'Nam', N'Nữ')),
	lop varchar(5)
)

create table monhoc
(
	mamh varchar(10) primary key,
	tenmh nvarchar(40) not null,
	sotinchi int check(sotinchi between 1 and 10)
)

create table diem
(
	masv varchar(10),
	mamh varchar(10),
	diemlan1 float check(diemlan1 between 0 and 10),
	diemlan2 float check(diemlan2 between 0 and 10),
	primary key(masv, mamh)
)
--tao khoa ngoai
alter table diem
add
	constraint fk_diem_sv
	foreign key(masv)
	references sinhvien(masv),
	constraint fk_diem_mh
	foreign key(mamh)
	references monhoc(mamh)

--them cot ghichu vao bang diem
alter table diem
add ghichu nvarchar(100)
--sua cot ghichu thanh nvarchar(90)
alter table diem
alter column ghichu nvarchar(90)

--xoa cot ghichu trong bang diem
alter table diem
drop column ghichu

--them rang buoc khoa ngoai trong bang diem
alter table diem
add
	constraint fk_diem_sv
	foreign key (masv)
	references sinhvien(masv),
	constraint fk_diem_mh
	foreign key (mamh)
	references monhoc(mamh)

insert into sinhvien(masv, hoten, gioitinh, lop) 
values 
('000113', N'Nguyễn Minh Long', N'Nam', 'L01'),
('000112', N'Nguyễn Đắc Đăng', N'Nam', 'L01');

select * from sinhvien

select * from diem