import numpy as np
import matplotlib.pyplot as plt

#we load the files containing tha data we want to process
eigenvalues1 = np.loadtxt("eigenvaluesn10.txt")
eigenvectors1 = np.loadtxt("eigenvectorsn10.txt")
eigenvalues2 = np.loadtxt("eigenvaluesn100.txt")
eigenvectors2 = np.loadtxt("eigenvectorsn100.txt")

#We define the analytical solution with a scaling factor to make it easier to compare the shapes of the functions
def analytical_eigenvector(k, x, L, scaling_fac):
    return np.sqrt(2 / L) * np.sin((k + 1) * np.pi * x / L)/scaling_fac

#we define a function that plots both the data and the analytical solution scaled in the same plot
def plot_and_save_eigenvectors(x_values, eigenvectors, num_eigenvectors, n_value, filename_prefix,scaling_fac):
    plt.figure()
    plt.title(f"Lowest {num_eigenvectors} Eigenvectors for n={n_value}")
    for i in range(num_eigenvectors):
        plt.plot(x_values, np.concatenate(([0], eigenvectors[:, i], [0])), label=f"Eigenvalue {i + 1}")
    for i in range(num_eigenvectors):
        analytical_values = [analytical_eigenvector(i, x, 1, scaling_fac) for x in x_values]
        plt.plot(x_values, analytical_values, linestyle='--', label=f'Analytical {i + 1}')
    plt.xlabel("Position (x_i)")
    plt.ylabel("Eigenvector Element")
    plt.legend()
    plt.savefig(f"{filename_prefix}_n{n_value}.jpg") #we save the plot as well as printing it 
    plt.show()

n1 = len(eigenvalues1)
n2 = len(eigenvalues2)
x_values1 = np.linspace(0, 1, n1 + 2)
x_values2 = np.linspace(0, 1, n2 + 2)

#we run the function for both our data sets
plot_and_save_eigenvectors(x_values1, eigenvectors1, 3, 10, "Problem6plot1",4)
plot_and_save_eigenvectors(x_values2, eigenvectors2, 3, 100, "Problem6plot2",10)