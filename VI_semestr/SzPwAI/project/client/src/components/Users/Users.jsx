import User from "../User/User";

function Users(props) {
  const users = props.users;
  return (
    <ul>
      {users.map((user) => (
        <User key={user._id} value={user._id} user={user} />
      ))}
    </ul>
  );
}

export default Users;
