-- Tạo bảng Khoa
CREATE TABLE khoa(
    makhoa varchar(10) PRIMARY KEY NOT NULL,
    tenkhoa nvarchar(50) NOT NULL
);

-- Tạo bảng MonHoc
CREATE TABLE monhoc(
    mamon varchar(10) PRIMARY KEY NOT NULL,
    tenmon nvarchar(50) NOT NULL,
    sotinchi int NOT NULL CHECK (sotinchi >= 1 AND sotinchi <= 10)
);

-- Tạo bảng SinhVien
CREATE TABLE sinhvien(
    masv varchar(10) PRIMARY KEY NOT NULL,
    hoten nvarchar(50) NOT NULL,
    ngaysinh date NOT NULL CHECK (ngaysinh < GETDATE()),
    makhoa varchar(10) NOT NULL
);

-- Tạo bảng DangKyHoc
CREATE TABLE dangkyhoc(
    masv varchar(10) NOT NULL,
    mamon varchar(10) NOT NULL,
    hocky int NOT NULL CHECK (hocky >= 1 AND hocky <= 8),
    PRIMARY KEY (masv, mamon)
);

-- Thêm khóa ngoại
ALTER TABLE sinhvien
ADD
CONSTRAINT fk_sv_makhoa
FOREIGN KEY (makhoa) REFERENCES khoa(makhoa);

ALTER TABLE dangkyhoc
ADD 
    CONSTRAINT fk_dkh_sv
    FOREIGN KEY (masv) REFERENCES sinhvien(masv),
    CONSTRAINT fk_dkh_monhoc
    FOREIGN KEY (mamon) REFERENCES monhoc(mamon);

-- Chèn dữ liệu vào bảng Khoa
INSERT INTO khoa (makhoa, tenkhoa) VALUES
('TOAN', N'Toán'),
('CNTT', N'Công nghệ Thông tin'),
('DIAL', N'Địa lý'),
('HOAH', N'Hóa học');
select * from khoa

-- Chèn dữ liệu vào bảng MonHoc
INSERT INTO monhoc (mamon, tenmon, sotinchi) VALUES
('GT1', N'Giải tích 1', 2),
('DSTT', N'Đại số tuyến tính', 3),
('HH', N'Hình học Afin', 2);
select * from monhoc
delete from monhoc

-- Chèn dữ liệu vào bảng SinhVien (dùng định dạng date)
INSERT INTO sinhvien (masv, hoten, ngaysinh, makhoa) VALUES
('K611', N'Pham Văn Bình', '1990-02-24', 'TOAN'),
('K612', N'Nguyễn Thị Hoài', '1991-04-12', 'CNTT'),
('K613', N'Trần Ngọc', '1990-04-15', 'DIAL'),
('K614', N'Nguyễn Tấn Dũng', '1992-02-03', 'CNTT'),
('K615', N'Trương Tấn Sang', '1990-12-04', 'DIAL');
select * from sinhvien

INSERT INTO dangkyhoc (MaSV, MaMon, HocKy) VALUES
('K611', 'GT1', 1),
('K611', 'DSTT', 2),
('K612', 'DSTT', 1),
('K612', 'HH', 2),
('K612', 'GT1', 1),
('K613', 'HH', 1),   -- Chọn 1 trong 2: (1) hoặc (2)
('K613', 'GT1', 8),
-- ('K613', 'HH', 2),  -- Bỏ dòng này vì trùng (K613, HH)
('K614', 'HH', 3),
('K614', 'DSTT', 6),
('K615', 'HH', 5);
select * from dangkyhoc

-- 3 --
update monhoc
set tenmon = N'Hình học'
where tenmon = N'Hình học Afin'

--4--
go
create view SinhVien_CNTT_1991 as
select * from sinhvien
where makhoa='CNTT' and year(ngaysinh) = 1991
go
select * from SinhVien_CNTT_1991

--5--
select * from sinhvien
where masv not in (
    select masv from dangkyhoc
    where mamon='GT1'
)

--6--
select sv.masv, sv.hoten, count(*) as Tongsomon
from sinhvien sv
join dangkyhoc  dkh on sv.masv=dkh.masv
group by sv.masv, sv.hoten
having count(*)>=2

--7--
select * from monhoc
where sotinchi>(select sotinchi from monhoc where tenmon=N'Giải tích 1')

--8-- sai
go
create proc sosvtheotungmon as
select mh.mamon, mh.tenmon, count(masv) as Tongsvien
from monhoc mh
join dangkyhoc dkh on mh.mamon = mh.mamon
group by mh.mamon, mh.tenmon

exec sosvtheotungmon