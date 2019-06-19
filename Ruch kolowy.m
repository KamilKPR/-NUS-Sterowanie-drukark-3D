
% drukarka = serial('/dev/ttyUSB0');
% drukarka.BaudRate=115200;
% fopen(drukarka);



%% zadanie jaza gora-dol

stare_k1 = ceil(sin(2*pi/3)*500)
stare_k2 = ceil(sin(-2*pi/3)*500);
stare_k3 = 0;

x = 0;
for i=0:0.1:30
    k1 = ceil(sin(i+2*pi/3)*500)
    k2 = ceil(sin(i-2*pi/3)*500)
    k3 = ceil(sin(i)*500)
    
    fprintf(drukarka,'k1 %d k2 %d k3 %d\n',[k1-stare_k1 k2-stare_k2 k3-stare_k3 ]);
    
    while(drukarka.BytesAvailable==0) % sprawdzenie czy jest pusto
        ;
    end
    while(drukarka.BytesAvailable > 0) % sprawdzenie czy mamy komunikat
       fscanf(drukarka)
    end    
    stare_k1 = k1;
    stare_k2 = k2;
    stare_k3 = k3;
    % fprintf(drukarka,'k1 -200 k2 -200 k3 -200');

%     while(drukarka.BytesAvailable==0)
%         ;
%     end
%     while(drukarka.BytesAvailable > 0)
%       fscanf(drukarka) 
%     end 
end
%% odpowiedz drukarki
