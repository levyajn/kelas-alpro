# Importing necessary packages
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
%matplotlib inline

newparams = {'figure.figsize': (15, 7), 'axes.grid': False,
             'lines.markersize': 10, 'lines.linewidth': 2,
             'font.size': 15, 'mathtext.fontset': 'stix',
             'font.family': 'STIXGeneral', 'figure.dpi': 200}
plt.rcParams.update(newparams)

# Constants

g = 9.81             # Force of gravity per kilo on earth's surface
alpha = 2.5          # Parameter in the adiabatic air density model
a = 6.5 * 10 ** (-3) # Parameter in the adiabatic air density model
T_0 = 288            # Temperature at sea level
m = 50               # Mass of the projectile
B = 2 * 10 ** (-3)   # Constant based on the Paris gun
v_0 = 1640           # Initial velocity


# Wind strength. This is a constant that never varies 
V = np.zeros(2) # Starting of with no wind


def f(w):
    """ A function describing the right hand side of the equations
    of motion/the set of ODEs.
    Parameter:
        w       vector containg the needed coordinates and their velocities 
    """
    # V : the vector describing the wind strength and direction
    temp_vector = np.zeros(4)
    temp_vector[0] = w[2]
    temp_vector[1] = w[3]
    # Saving the next parameters in order to optimize run time
    k = (1 - a * w[1] / T_0)   # Air density factor
    s = np.sqrt((w[2]-V[0]) * 2 + (w[3]-V[1]) * 2 )
    if k>0:
        temp_vector[2] = - B / m * k ** (alpha) * (w[2]-V[0]) * s
        temp_vector[3] = - B / m * k ** (alpha) * (w[3]-V[1]) * s - g
    else:
        temp_vector[2] = 0 
        temp_vector[3] = - g
    return temp_vector 


def RK4_step(f, w, h):
    """Performing a single step of the Runge-Kutta fourth order method.
    Parameters:
        f      RHS of ODEs to be integrated
        w      numerical approximation of w at time t
        h      unit/integration step length
    Returns:
        numerical approximation of w at time t+h
    """
    s1 = f(w)
    s2 = f(w + (h / 2) * s1)
    s3 = f(w + (h / 2) * s2)
    s4 = f(w + h * s3)
    return w + (h / 6) * (s1 + (2 * s2) + (2 * s3) + s4)

def shoot(theta, v0):
    """ Initializes the vector w (x and y position and velocity of the
    projectile) given a initial shooting angle, theta, and 
    absolute velocity, v0. 
    """
    w = np.zeros(4)
    w[2] = v0 * np.cos(np.deg2rad(theta))
    w[3] = v0 * np.sin(np.deg2rad(theta))
    return w


def projectile_motion(h, theta):
    """ Calculates the motion of the projectile using the functions
    defined above. While the projectile is in the air (w[1] >=0) the 
    position and velocity is updated using a single step of RK4.
    Parameters:
        h        unit/integration step length
        theta    initial shooting angle
    Returns:
        X_list   array of the projectile's x-position
        Y_list   array of the porjectile's y-position
    """
    w = shoot(theta, v_0)
    X_list = np.zeros(0)
    Y_list = np.zeros(0)
    while  w[1] >= 0:
        w = RK4_step(f, w, h)
        X_list = np.append(X_list, w[0])
        Y_list = np.append(Y_list, w[1])
    return X_list, Y_list

def find_optimal_angle(h):
    """ Given an integration time step, this function calculates the optimal initial 
    shooting angle for the projectile to obtain maximum range, in x-direction. The 
    set of angles tested, with their corresponding range, along with the optimal
    angle are returned.
    """
    
    record = 0        # Placeholder variable that holds the maximum range
    optimal_angle = 0 # Placeholder variable that holds the angle yielding the maximum range
    # Lists containing the initial angle and its corresponding range
    theta_list = np.zeros(0) 
    range_list = np.zeros(0)
    for theta in range (1,90,2):
        x_list, y_list = projectile_motion(h, theta)
        # Using linear interpolation do determine the landing point more precisely
        m = (y_list[-1] - y_list[-2]) / (x_list[-1] - x_list[-2])   # The landing point
        x_range = - y_list[-1] / m + x_list[-1] 
        theta_list = np.append(theta_list, theta)
        range_list = np.append(range_list, x_range)
        # Update records
        if x_range >= record:
            record = x_range
            optimal_angle = theta

    # Rerunning the same code on a smaller interval in order to approximate the optimal angle
    # more precicely
    theta_list_smaller = np.linspace(optimal_angle - 2, optimal_angle + 2, 41)
    for theta_small in theta_list_smaller:
        x_list, y_list = projectile_motion(h, theta)
        # Again, using linear interpolation do determine the landing point more precisely
        m = (y_list[-1] - y_list[-2]) / (x_list[-1] - x_list[-2])
        x_range = - y_list[-1] / m + x_list[-1]
        if x_range >= record:
            record = x_range
            optimal_angle = theta_small
            
    return theta_list, range_list, optimal_angle

theta, x , best = find_optimal_angle(0.1)

print("The optimal angle is: ", best, " degrees")

plt.plot(theta, x/1000)
plt.title(r"Projectile range as a function of shooting angle, $\theta$")
plt.xlabel(r"$\theta $ [$\degree$]")
plt.ylabel(r"range [km]")

def trajectories(h):
    plt.figure()
    plt.title("Projectile trajectories by alternating shooting angle")
    plt.xlabel(r"x [km]")
    plt.ylabel(r"y [km]")
    theta_list = np.arange(30.0,75,5)
    for angle in theta_list:
        x_list, y_list = projectile_motion(h, angle)
        plt.plot(x_list/1000, y_list/1000, '--', label=r'$\theta = $%.i $\degree$'%(angle))
    plt.legend(loc='best')
    plt.gca().set_ylim(bottom=0)
    plt.show()
trajectories(0.1)