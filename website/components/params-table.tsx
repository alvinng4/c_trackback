'use client'

interface Param {
  name: string;
  type: string;
  desc: string;
}

interface ParamsTableProps {
  params?: Param[];
}

export default function ParamsTable({ params }: ParamsTableProps) {
  if (!params || params.length === 0) return null;

  return (
    <div className="mt-6 mb-10">
      <div className="w-full overflow-x-auto">
        <table className="w-full text-left border-collapse">
          <thead>
            <tr className="border-b border-gray-200 dark:border-gray-800">
              <th className="py-2 pr-8 text-xs font-semibold uppercase tracking-wider text-gray-500 dark:text-gray-400">
                Name
              </th>
              <th className="py-2 pr-8 text-xs font-semibold uppercase tracking-wider text-gray-500 dark:text-gray-400">
                Type
              </th>
              <th className="py-2 text-xs font-semibold uppercase tracking-wider text-gray-500 dark:text-gray-400">
                Description
              </th>
            </tr>
          </thead>
          <tbody className="divide-y divide-gray-100 dark:divide-gray-800">
            {params.map((p) => (
              <tr key={p.name}>
                <td className="py-3 pr-8 align-top">
                  <code className="ml-2 align-middle text-sm px-2 py-0.5 rounded font-medium bg-blue-100 text-blue-800 dark:bg-blue-900 dark:text-blue-300">
                    {p.name}
                  </code>
                </td>
                <td className="py-3 pr-8 align-top">
                  <code className="text-xs bg-gray-100 dark:bg-gray-800 text-gray-600 dark:text-gray-300 px-1.5 py-0.5 rounded border border-gray-200 dark:border-gray-700">
                    {p.type}
                  </code>
                </td>
                <td className="py-3 text-sm text-gray-600 dark:text-gray-400 align-top">
                  {p.desc}
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </div>
  );
}
