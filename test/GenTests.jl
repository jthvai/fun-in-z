# SPDX-License-Identifier: X11
# 2020-11-14

using Random

function geninput(bound::Integer, fn::AbstractString)
  X = collect(-bound:bound)
  Y = collect(-bound:bound)
  n = 2bound + 1

  println("Shuffling...")

  shuffle!(X)
  shuffle!(Y)

  println("Printing to $fn...")
  open(fn, "w") do f
    for i ∈ 1:n
      println(f, join([string(i, base=16),
                       string(X[i]),
                       string(Y[i])],
                      " "))
    end
  end
end
