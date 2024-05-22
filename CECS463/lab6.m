fs = 10000;
tStop = 3;
T=0.01;
Amp = 200; 



tt = 0:(1/fs):tStop;
qq =rem(tt,T);
xx = Amp*(abs(qq-(0.5*T))-0.25*T);


plot(tt, xx);
ylim([-.75, .75]);
