#!/bin/bash

#SBATCH --job-name=calculate-pi
#SBATCH --partition=arm128c256g
#SBATCH --output=./outlog/calculate-pi.out
#SBATCH --error=./errlog/calculate-pi.err
#SBATCH -n 1
#SBATCH --ntasks-per-node=4

ulimit -l unlimited
ulimit -s unlimited

module load gcc

export OMP_NUM_THREADS=8
let start_time=$(date +%s)
./calculate-pi
let end_time=$(date +%s)
cost_time=`expr $end_time - $start_time`
echo "totally cost time is $cost_time s"