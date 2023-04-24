#清空变量 包含dos栏和工作区
Clear
Clc

#参数配置
cellLen = 3.75;#元胞长度
safeDis = 1;
p=0.1;
deltaTime=1;#间隔时间（标准时）
Gif=1;#是否开启动图

#迭代部分
stepCur=0;
stepMax=1000;
pauseTime=0.01;
alphaMat=linspace(0,1,stepMax);#从0到1的mat矩阵
betaMat=linspace(1,0,stepMax);#从1到0的Mat矩阵

#路段信息
road.len=1500;
road.cellSum=road.len/cellLen;
road.num=2;
road.imageMat=zeros(road.num,road.cellSum);
road.cntMat=zeros(road.num,road.cellSum);
road.velMat=zeros(road.num,road,cellSum);

#小汽车信息
Car.cellLen=2
Car.velMax=5;
Car.velMat=zeros(1,stepMax+1);
Car.aveVel=zeros(1,stepMax+1)

#公交车信息
Bus.flow=30
Bus.velMax=3;
Bus.velE=2;
Bus.cellLen=4;
Bus.aveVel=zeros(1,stepMax+1);
Bus.roadNum=2;#公交车只能在第二车道运行
Bus.notRoadNum=find(~ismember(1:road.num,Bus.roadNum));

#仿真参数
Choice0=menu(‘请选择车辆类型’,专用车道’’,’非专用车道’);
H=imshow(road.imageMat);
Switch choice0
   Case 1
 	mode=‘专用车道’；
   Case 2
	mode=‘非专用车道‘；
 end

#迭代仿真
While stepCur<stepMax
stepCur=stepCur+1;
alaph=alphaMat(stepCur);
beta=beta(stepCur);








If Gif
       set(H,’CData’,road.imageMat);
       pause(pauseTime);
       title(‘仿真时间’，nim2str(stepCur,‘秒’))；

#function1 
If car.avel(steCur)>bus.velE
appearCarFlag=1;
Else
clearTime=road.cellSum*(bus.velE-car.aveVel(stepCur))/bus.velE/car.aveVel(stepCur)#函数部分
 	if(bus.flow-rem(stepCur,bus.flow))>clearTime




#function2公交车代码
Function appearBus
roadInfo = road.image(bus.roadNum,1:bus.cellLen);
If sum(roadinfo)
Road.imageMat(bus.roadNum,1:bus.cellLen ) =2;
Road.cntMat(bus.roadNum,bus.cellLen)=2;
Road.velMat(bus.roadNum,bus.cellLen)=bus.velE

#function3
road=appearCar(road, bus,appearCarflag,car,alpha)
Function appearCar
Rand=rand; #rand为Matlab里的一个函数，随机生成0——1之间的数。
For k1=1:road.num
 If k1==bus.roadNum
     If appearCarflag && (alpha>Rand)
roadinfo=road.imageMat(k1,1:car.cellLen);
        If sum(roadinfo)
Road.imageMat(k1,1:car.cellLen)=1;
road.cntMat(k1,car.cellLen)=1;
Road.velMat(k1,car.cellLen)=car.velMax;
End
End
End
 If alpha>Rand
roadinfo=road.imageMat(k1,1:car.cellLen);
        If sum(roadinfo)
Road.imageMat(k1,1:car.cellLen)=1;
road.cntMat(k1,car.cellLen)=1;
Road.velMat(k1,car.cellLen)=car.velMax;
End
End
End

#function4衔接下文
chagerRoad

thisMat=[1,2];
notThis=@(this) thisMat(this~=thisMat)
For k3=1:1:road.cellSum
If road.cntMat(bus.roadNum,k3)==2
lastBusCoor=[bus.roadNum,k3];
Break;
End
End
For k4=road.cellSum-1:-1:2
For k5 =1:road.num
If k5==bus.roadNum
If road.cntMat(k5,k4)==1
selfFronDis=calcuSelfFrontDis(k4,k5,road);
sideFronDis=calcuSideFrontDIs(k4,notThis(k5),road);
calcuSideBackDIs

#function5小汽车换道本行本列与前车道距离
Function calcuSelfFront
selfFrontFLag=1;
While col+selgFrontFlag<=road.cellSum
If road.imageMAt(line,col+selfFrontFlag) selfFrontDis=selfFrontFlag-1;
Break;
End
selfFrontFlag=selfFrontFlag+1;
End
If col+selfFrontFlag>=road.cellSum
selfFrontDis=inf
End

#function6 旁车道前距
Function calcuSideFronDis
sideFronflag=1;
While col+sideFronflag<=road.cellSum
If road.imageMAt(sideLine,col+sideFrontFlag)
Road.imageMat=(sideLine, col+sidefronFlag);
sideFronDis=sideFrontFlag-1;
Break;
End
sideFronFlag=sideFronFlag+1;
End
If col+sideFronFlag>=road.cellRoad
If col+sideFrontFlag>=road.cellSum
sideFrontDis=inf
End

#function7旁车道后距 function calcuSideBackDis
sideBackDis=inf;
sideBackFlag=1;
col=col-car.cellLen+1
While col-sideBackFlag>=1
If road.imageMat(Sideline,col-sideBackFlag)
sideBackDis=sideBackFlag-1;
Break;
End
sideBackFlag=sideBackFlag+1;
End
