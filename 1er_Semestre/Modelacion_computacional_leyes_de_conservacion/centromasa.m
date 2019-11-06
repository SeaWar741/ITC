clc
close all
clear all
A = rgb2gray(imread('./car.jpg'));  %para este caso, poner fondo blanco en la imagen

%% INITIALIZE VARIABLES
A(isnan(A)) = 0;
if ~(strcmpi(class(A),'double') || strcmpi(class(A),'single'))
A = single(A);
end
if any(A(:)<0)
warning('MATLAB:centerOfMass:neg','Array A contains negative values.');
end
%% PROCESS
sz = size(A);
nd = ndims(A);
M = sum(A(:));
C = zeros(1,nd);
if M==0
C = [];
else
for ii = 1:nd
shp = ones(1,nd);
shp(ii) = sz(ii);
rep = sz;
rep(ii) = 1;
ind = repmat(reshape(1:sz(ii),shp),rep);
C(ii) = sum(ind(:).*A(:))./M;
end
end
% Assemble the VARARGOUT cell array
varargout = {C};
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
equis = num2str(round(C(1)));
ye=num2str(round(C(2)));
figure;
imagesc(A); 
colormap gray; 
axis image

hold on; 
plot(C(2),C(1),'r*')
 

txt = ['\leftarrow' equis 'î, ' ye 'j'];
text(C(2)+10,C(1),txt,'Color','red','FontSize',14)

%text(C(2),C(1),' \leftarrow î',equis,'FontSize',18)
%%
