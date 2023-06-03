# 2022-1_OSSLab_FinalProject

---

### What does this project do?
1. It saves safe random generated to your protected database in your raspberry pi server.  
2. Creates a constant safe master password.  

### Why is this project useful?
Personally, I tend to forget my passwords a lot.  
This project creates and saves safe passwords to the database.  
Then can be easliy acccessed by the user for use.  

---

### Before Getting Started
###### Prepare the following:
1. Raspberry pi.
---

### How to use
1. Clone the repository.
```
git clone https://github.com/young170/2022-1_OSSLab_FinalProject.git
```
2. In Main.c edit the server, user, password, database variables to match your settings.
```
char *server = "";     //your ip.
char *user = "";       //your db id.
char *password = "";   //your db password.
char *database = "";   //your db name
```
3. Install Maraiadb on raspberry pi.
```
sudo apt-get update
sudo apt-get install mariadb-server
```
4. Create Maraiadb user.
```
sudo mysql
create user root@localhost identified by 'your_password';
grant all privileges on *.* to root@localhost;
FLUSH PRIVILEGES;
exit;
```
5. Configure mariadb settings.  
  A. Edit bind-address to 0.0.0.0. 
```
sudo nano /etc/mysql/mariadb.conf/50-server.cnf
```
6. Compile using the following command.
```
gcc Main.c Header.h -L/usr/lib/mysql -lmysqlclient -I/usr/lib/mysql/include
```
7. Interact with program.

---

### Video
https://youtu.be/XqpfUJTImzM  

### References
<https://qnaplus.com/how-to-access-mysql-database-from-c-program/>  
<https://github.com/mehrzero/random_password_generator>

### My contributions to the project  
100% original idea from creator and started from scratch. 

---

### Information
Email me if you need help:)  
22100113@handong.ac.kr
