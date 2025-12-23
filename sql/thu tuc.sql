select * from monhoc
go

create proc tongtinchi(@mh1 varchar(10), @mh2 varchar(10))
as
begin
declare @tc1 int
declare @tc2 int
declare @tong int
select @tc1=sotinchi from monhoc where mamh=@mh1
select @tc2=sotinchi from monhoc where mamh=@mh2
select @tong=@tc1+@tc2
print 'Tổng số tín chỉ là: '+str(@tong)
end
go
exec tongtinchi 'CSDL', 'TRR'
go
create proc sosanhmh (@mh1 varchar(10), @mh2 varchar(10))
as
begin
declare @tc1 int
declare @tc2 int
select @tc1=sotinchi from monhoc where mamh=@mh1
select @tc2=sotinchi from monhoc where mamh=@mh2
if @tc1=@tc2 print N'2 môn có cùng số lượng tín chỉ'
else if @tc1 > @tc2 print N'môn '+@mh1+N' có số tín chỉ nhiều hơn '+@mh2
else print N'môn '+@mh2+N' có số tín chỉ nhiều hơn '+@mh1
end
go
sosanhmh 'CSDL', 'TRR'
go
---------------------------------------------
create proc sl(@mh varchar(10), @sl int output)
as
select @sl=sotinchi from monhoc where mamh=@mh
go
create proc tong(@mh1 varchar(10), @mh2 varchar(10))
as
declare @sl1 int
declare @sl2 int
declare @tong int
exec sl @mh1, @sl1 output
exec sl @mh2, @sl2 output
set @tong=@sl1+@sl2
print N'Tổng = '+str(@tong)
go
tong 'CSDL', 'TRR'