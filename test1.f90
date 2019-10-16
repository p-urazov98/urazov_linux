subroutine processingmatrixA(A,n,m,maxi0,maxj0,mini0,minj0,max,min,Summ,AverageArifm)
IMPLICIT NONE
Real,Dimension(n,m),intent(in)::A
Integer,intent(in)::n,m
Real,intent(out)::max,min,Summ,AverageArifm
integer,intent(out)::maxi0,maxj0,mini0,minj0
Integer::i,j
Summ=0
max=A(1,1)
min=A(1,1)
Do i=1,n
 Do j=1,m
  Summ=Summ+A(i,j)
  If(A(i,j).GE.max) Then
   max=A(i,j)
   maxi0=i
   maxj0=j
  else if(A(i,j).LE.min) Then
   min=A(i,j)
   mini0=i
   minj0=j
  End if
  End do
End do
AverageArifm=Summ/(m*n)
end Subroutine processingmatrixA

Subroutine processingmatrixB(matrixA,matrixB,n,m,maxi0,maxj0,mini0,minj0,AverageArifm)
IMPLICIT NONE
Real,Pointer,intent(out)::matrixA(:,:),matrixB(:,:)
Integer,intent(in)::n,m,maxi0,maxj0,mini0,minj0
Real,intent(in)::AverageArifm
Integer::i,j
Allocate(matrixB(n,m))
Do i=1,n
 Do j=1,m
  If((i.EQ.mini0).And.(j.EQ.minj0)) Then
     matrixB(i,j)=AverageArifm
  else If((i.EQ.maxi0).And.(j.EQ.maxj0)) Then
     matrixB(i,j)=AverageArifm
  else
     matrixB(i,j)=matrixA(i,j)
  End if
End Do
End Do

End Subroutine processingmatrixB

Subroutine readarray(filename,matrixA,n,m,Error)
IMPLICIT NONE
Character(*),intent(in)::filename
Real,Pointer,intent(out)::matrixA(:,:)
Integer,intent(out)::n,m
Logical isExist
Integer::i,j,Error
Error=0
Inquire(FILE=filename,Exist=isExist)
If(isExist) Then
 Open(1,FILE=filename,STATUS='OLD',ACTION='READ')
else
 pause
  Error=1
end if
1 Format(I1,TR1,I1)
Read(1,1) n,m
Allocate(matrixA(n,m))
Do i=1,n
 Read(1,*) (matrixA(i,j),j=1,m)
End do
End Subroutine readarray

Subroutine writearray(file,matrixB,n,m)
Real,Pointer,intent(in)::matrixB(:,:)
Integer,intent(in)::n,m
Character(*),intent(in)::file
Open(2,File=file,STATUS='REPLACE',ACTION='WRITE')
Do i=1,n
  Write(2,*)(matrixB(i,j),j=1,m)
End Do
End Subroutine writearray

!Subroutine min_max(A,m,n,min,max,index_min,index_max)
!IMPLICIT NONE
!Integer,intent(in)::n,m
!Real,dimension(n,m),intent(in)::A
!integer,dimension(m*n,2)::index
!real,intent(out)::min,max
!End Subroutine min_max

Program ExerTest
IMPLICIT NONE
Real,Pointer:: A(:,:),B(:,:)
Integer:: n,m,k,i,j,Error
Character(10)::word,name1,name2
Real::max,min,Summ,AverageArifm
Integer::maxi0,maxj0,mini0,minj0
word='yes'
Do While(word=='yes')

Print*,'Start(yes)?'
Read(*,*) word
If(word/='yes') Then
exit
End if
Print*,'Input name file'
Read(*,*) name1

call readarray(name1,A,n,m,Error)

If(Error/=0) Then 
Print*,'Mistake took place in procedure of reading:error',Error
End if

call processingmatrixA(A,n,m,maxi0,maxj0,mini0,minj0,max,min,Summ,AverageArifm)
call processingmatrixB(A,B,n,m,maxi0,maxj0,mini0,minj0,AverageArifm)

Print*,'Input savefile'
Read(*,*) name2

call writearray(name2,B,n,m)

close(1)
close(2)

Print*,'Max',max
Print*,'Min',min
Print*,'Summ',Summ
Print*,'Average',AverageArifm

DeAllocate(A,B)

End do
pause
end Program ExerTest
