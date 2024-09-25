# A HPC learner's notes
Platform Used: arm128c256g

## Structure
local-->login nodes-->computing nodes

use ssh to connect login nodes from local

use SLURM to upload an assignment from login nodes to computing nodes

## SLURM
Usage:write a xxx.slurm-->sbatch xxx.slurm

Following is an example for slurm script:

'''shell

#!/bin/bash                     \\shell file head

#SBATCH --job-name=hello_world  \\the name of the job you submitted
#SBATCH --partition=small       \\the computing node you choose
#SBATCH --output=%j.out         \\the output log file name
#SBATCH --error=%j.err          \\the error log file name
#SBATCH -n 8                    \\the number of computing nodes you applied
#SBATCH --ntasks-per-node=8     \\the number of threads used per node

                                \\shell script running on computing nodes
ulimit -l unlimited             \\
ulimit -s unlimited             \\set the limit of stack to unlimited

module load gcc

export OMP_NUM_THREADS=8
./hello_world                   \\file on login node will be uploaded automatically

'''