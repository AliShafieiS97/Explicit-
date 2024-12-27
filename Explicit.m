
landa = input("Thermal Conductivity: ");
rho = input("Density: ");
Cp = input("Specific Heat: ");
alpha=landa/(rho*Cp);

L = input("Length of Beam: ");
Time = input("Total Time: ");
deltax = input("DeltaX: ");
deltat = input("Deltat: ");

N = L/deltax;
M = Time/deltat;


convergence_index=(deltat*alpha)/(deltax*deltax);

T = zeros(M,N);

if (convergence_index < 0.5)

    
    T(1,:) = 30; %initial condition 
    T(:,1) = 100; %boundary condition (x=0)
    T(:,N) = 20; %boundary condition (x=100)


    for j=1:M-1
        for i=2:N-1
            T(j+1,i)=(((alpha*deltat)/(deltax*deltax))*(T(j,i+1)-2*T(j,i)+T(j,i-1))+T(j,i));
       
        end
    end
else 
    disp("Error! Please refine deltax and deltat.");

end

figure; 
plot(0:deltat:Time-deltat,T(:,N/2)); 
xlabel('t(s)');
ylabel('T (x=0.5m)');
title('Temperature distribution over time at x = 0.5 m');
legend('show');
grid on; 


figure; 
plot(0:deltax:L-deltax,T(800/deltat,:));
xlabel('x (m)');
ylabel('T (t = 800 s)');
title('Temperature distribution along beam at t = 800 s');
legend('show');
grid on; 

disp ("T(x=0.75,t=600): ");
disp(T(600/deltat,0.75/deltax));

