import jax
import jax.numpy as jnp

def f(x):
  return x * jnp.sin(x)

def process_data(inputs):
  print("(python) computing dfdx elementwise ... ")
  return jax.vmap(jax.grad(f))(jnp.array(inputs))

if __name__ == "__main__":
  print(process_data([1.0, 2.0, 3.0]))