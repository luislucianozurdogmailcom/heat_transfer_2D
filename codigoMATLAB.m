clear all;
close all;

B=load('TemperaturasyFlujos.txt');
A=load('malladoMatlab.txt');
x=A(1);
y=A(2);
t=A(3);
[X,Y]=meshgrid(1:1:x,1:1:y);

figure(1)
v=VideoWriter('DominioCircular');
v.FrameRate=20;
open(v)

set(gcf,'Renderer','zbuffer')

for k=0:3:(3*t)

surfc(X,Y,B((k*y)+1:y*(k+1),:));
zlim([20 40]);
shading interp;

view(3);
drawnow;
frame=getframe(1);
writeVideo(v,frame);

end
close(v)

figure(2)
v=VideoWriter('DominioCircularFlujos');
v.FrameRate=20;
open(v)

set(gcf,'Renderer','zbuffer')

for k=0:3:(3*t)

quiver(X,Y,B(((k+1)*y)+1:y*(k+2),:),B(((k+2)*y)+1:y*(k+3),:))
drawnow;
frame=getframe(2);
writeVideo(v,frame);

end
close(v)
