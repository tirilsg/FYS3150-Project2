import numpy as np
import matplotlib.pyplot as plt

#Open the files containing eigenvalues and eigenvectors for n=10 and n=100 
eigenvalues1 = np.loadtxt("eigenvaluesn10.txt")
eigenvectors1 = np.loadtxt("eigenvectorsn10.txt")
eigenvalues2 = np.loadtxt("eigenvaluesn100.txt")
eigenvectors2 = np.loadtxt("eigenvectorsn100.txt")

#We define the function that plots the three first eigenvectors for the eigenvalues
def plot_and_save_eigenvectors(x_values, eigenvectors, num_eigenvectors, n_value, filename_prefix):
    plt.figure()
    plt.title(f"Lowest {num_eigenvectors} Eigenvectors for $n={n_value}$")
    for i in range(num_eigenvectors):
        plt.plot(x_values, np.concatenate(([0], eigenvectors[:, i], [0])), label=f"Eigenvalue {i + 1}")
    plt.plot(x_values[0], eigenvectors[0, 0], "x" , label="$(\hat{x}_0, v_0)$")
    plt.plot(x_values[-1], eigenvectors[-1, 0], "x",label="$(\hat{x}_n, v_n)$")
    plt.xlabel("Position ($\hat{x}_i$)")
    plt.ylabel("Eigenvector Element")
    plt.legend()
    plt.savefig(f"{filename_prefix}_n{n_value}.jpg")
    plt.show()

#we define the discretization parameters
n1 = len(eigenvalues1)
n2 = len(eigenvalues2)
x_values1 = np.linspace(0, 1, n1 + 2)
x_values2 = np.linspace(0, 1, n2 + 2)

#we plot and save eigenvectors for the two different n-values
plot_and_save_eigenvectors(x_values1, eigenvectors1, 3, 10, "Problem6plot1")
plot_and_save_eigenvectors(x_values2, eigenvectors2, 3, 100, "Problem6plot2")
