1.设置git的user name和email：
	$ git config --global user.name "myname"
	$ git config --global user.emali "myemail"
2.生成密钥：
	$ ssh-keygen -t rsa -C "myemail"
		按三个回车。
	Your identification has been saved in /home/tekkub/.ssh/id_rsa.
	Your public key has been saved in /home/tekkub/.ssh/id_rsa.pub.
	The key fingerprint is:
	………………
	此时，生成两个文件：id_rsa和id_rsa.pub
3.添加密钥：
	$ ssh -add ~/.ssh/id_rsa
4.将ssh密钥添加到GitHub账号：
	$ clip < ~/.ssh/id_rsa.pub
	profile photo -> Settings -> SSH and GPG keys -> New SSH key ->paste to 	"Key" field -> Add SSH key -> confirm password.
end.

Advice:声音不是很清晰（也无太大影响）
