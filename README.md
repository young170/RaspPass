# 2022-1_OSSLab_FinalProject

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
5. Compile using the following command.
```
gcc main.c header.h -L/usr/lib/mysql -lmysqlclient -I/usr/lib/mysql/include
```
6. Interact with program.

---

### References
<https://qnaplus.com/how-to-access-mysql-database-from-c-program/>
<https://github.com/mehrzero/random_password_generator>

---

### Information
22100113@handong.ac.kr
