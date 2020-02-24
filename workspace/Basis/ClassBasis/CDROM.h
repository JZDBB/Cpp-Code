#pragma once
enum CD_CONNECT { SATA, USB };
enum CD_INSTALL { external, bulit_in };
class CDROM {
private:
	CD_CONNECT con;
	CD_INSTALL install;
	int cdvolume;
public:
	CDROM(CD_CONNECT c, CD_INSTALL i, int cv);
	CDROM();
	~CDROM();

	//数据接口
	CD_CONNECT GetCD_CONNECT()const;
	CD_INSTALL GetCD_INSTALL()const;
	int Getcdvolume()const;

	void setCD_CONNECT(CD_CONNECT c);
	void setCD_INSTALL(CD_INSTALL i);
	void setcdvolume(int cv);

	void run();
	void stop();
};

