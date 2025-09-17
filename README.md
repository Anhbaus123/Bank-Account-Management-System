# Bank-Account-Management-System
📝 OOA – Phân tích hướng đối tượng cho hệ thống Quản lý Tài khoản Ngân hàng
1. Xác định các đối tượng (Object Identification)

Trong hệ thống quản lý ngân hàng đơn giản này, ta có thể xác định các đối tượng chính:

Account (Tài khoản thường)

SavingsAccount (Tài khoản tiết kiệm – kế thừa từ Account)

Customer (Khách hàng)

Transaction (Giao dịch)

2. Xác định thuộc tính (Attributes)

Account

AccountNumber (Số tài khoản)

OwnerName (Tên chủ tài khoản)

balance (Số dư)

TransactionHistory (Lịch sử giao dịch)

SavingsAccount (kế thừa Account)

interestRate (lãi suất)

Customer

name (Tên khách hàng)

ID (Mã khách hàng)

accounts (Danh sách tài khoản thuộc sở hữu)

Transaction

type (Loại giao dịch: nạp, rút, lãi suất)

amount (Số tiền)

date (Ngày thực hiện)

3. Xác định phương thức (Methods)

Account

deposit(amount) → Nạp tiền

withdraw(amount) → Rút tiền

displayInfo() → Hiển thị thông tin

operator+= → Nạp tiền bằng toán tử

operator== → So sánh số dư

SavingsAccount

withdraw(amount) (ghi đè, chỉ cho phép rút ≤ 50% số dư)

applyInterest() → Áp dụng lãi suất

Customer

addAccount(Account*) → Thêm tài khoản

displayCustomerInfo() → Hiển thị thông tin khách hàng + tài khoản

Transaction

getInfo() → Xuất thông tin giao dịch

4. Xác định mối quan hệ (Relationships)

Customer – owns → Account (1 khách hàng có thể sở hữu nhiều tài khoản).
Account – has → Transaction (mỗi tài khoản có lịch sử nhiều giao dịch).
SavingsAccount – inherits → Account (tài khoản tiết kiệm kế thừa tài khoản thường).
Account – has → Transaction (mỗi tài khoản có lịch sử nhiều giao dịch).

SavingsAccount – inherits → Account (tài khoản tiết kiệm kế thừa tài khoản thường).
